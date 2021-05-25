while True:
    try:
        n=int(input())
        if n>0:
            print(f'{n}-->{bin(n)[2:]}')
        else:
            print(f'{n}-->{bin(n)[0]}{bin(n)[3:]}')
    except:
        break
    
