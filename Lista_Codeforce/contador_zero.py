numeros = list(map(int, input().split()))
cont = 0
for  i in range (0, len(numeros)):
    if(i+1 >= 467 and i+1 <= 476):
        cont += 1
        print(numeros[i])


print("qtd 0: ", cont) 
        