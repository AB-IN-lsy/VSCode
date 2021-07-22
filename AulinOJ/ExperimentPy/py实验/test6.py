import requests
from bs4 import BeautifulSoup  
import re
headers = {'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_12_3) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/56.0.2924.87 Safari/537.36'}
url = 'http://www.pm25.com/city/haerbin.html'

print("哈尔滨污染指数")

r = requests.get(url, headers = headers)
content = r.text
soup = BeautifulSoup(content, 'lxml') 
divs = soup.find_all('a')

reg = 'cbol_.*'

for div in divs:
    try:
        res = re.findall(reg, div['class'][0])
        if res:
            if div.string != None and res[0][-3:] == "num":
                print(div.string, end = "           ")
            elif res[0][-3:] == "ame":
                print(div.string)
            else:
                print(f"{div.span.get_text()}微克/立方米", end = "  ")
    except:
        pass
print("各个采样点AQI指标")

div2 = soup.find_all("ul", class_ = "pj_area_data_details")

loca = []
aqi = []
cnt = 0
for ul in div2:
    cnt += 1
    lis = ul.find_all('a')
    for li in lis:
        if li['class'][0] == 'pjadt_location':
            loca.append(li.string)
    spans = ul.find_all('span')
    for span in spans:
        if span['class'][0] == 'pjadt_aqi':
            aqi.append(span.get_text())
    d = dict(zip(loca, aqi))
    loca = []
    aqi = []
    for i in d:
        if cnt == 1:
            print(f"(中国标准) 地点: {i}  AQI: {d[i]}")
        else:
            print("---------------------------------")
            print(f"(美国标准) 地点: {i}  AQI: {d[i]}")