while True:
    try:
        s=input()
        n=int(input())
        import string as st
        before=st.ascii_lowercase+st.ascii_uppercase
        data1=st.ascii_lowercase
        data2=st.ascii_uppercase
        after=data1[n:]+data1[:n]+data2[n:]+data2[:n]
        table=''.maketrans(before,after)
        print(s.translate(table))
    except:
        break
