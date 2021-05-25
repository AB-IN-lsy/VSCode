while True:
    try:
        s=input()
        import string as st
        before=st.ascii_uppercase+st.ascii_lowercase
        data=st.ascii_lowercase
        after=data[1:]+data[:1]
        after=after+"22233344455566677778889999"
        table=''.maketrans(before,after)
        print(s.translate(table))
    except:
        break

