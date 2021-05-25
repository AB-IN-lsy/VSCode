import string as st
while True:
    try:
        s=input()
        if s=="END":
            break
        before=st.ascii_uppercase
        after="IBLeEIeHIJKYoNOeQRvTUVIuYZ"
        table=''.maketrans(before,after)
        print(s.translate(table))
    except:
        break
        
