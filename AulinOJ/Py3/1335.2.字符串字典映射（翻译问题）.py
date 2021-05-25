import string as st
while True:
    if input() == "ENDOFINPUT":
        break
    num=input()
    input()
    data=st.ascii_uppercase#返回一个全部大写字母的字符串
    after=data[5:]+data[:5]#字符串移五位
    before=data
    table=''.maketrans(after,before)#返回一个字典，形成两个链表ASC码的映射,after是输入的
    print(num.translate(table))#根据字典翻译字符串
