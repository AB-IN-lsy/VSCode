import string as st
while True:
    if input() == "ENDOFINPUT":
        break
    num=input()
    input()
    data=st.ascii_uppercase#返回一个全部大写字母的字符串
    after=data[5:]+data[:5]#字符串移五位
    before=data
    table=''.maketrans(after,before)#返回一个
    print(type(table))
    print(num.translate(table))
