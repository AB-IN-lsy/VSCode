import requests
from bs4 import BeautifulSoup  

headers = {'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_12_3) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/56.0.2924.87 Safari/537.36'}
base_url = 'https://www.qiushibaike.com/text/page/'
for num in range(1, 3): 
    print('第{}页'.format(num))

    r = requests.get(base_url + str(num), headers = headers) 
    content = r.text
    soup = BeautifulSoup(content, 'lxml') 
    divs = soup.find_all(class_ = 'article block untagged mb15 typs_hot')

    for div in divs:
        if div.find_all(class_ = 'thumb'):
            continue
        joke = div.span.get_text()
        print(joke)
        print('------')
