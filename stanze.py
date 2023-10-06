#Baffert ALexander
import json
#apertura json
def visualizza():
    with open("edificio.json", "r") as f:
        edificio=json.load(f)
    print(edificio)
def creazione_stanza():
    with open("edificio.json", "r") as f:
        stanza=json.load(f)
    #crezione delle stanze
    stanze=int(input("Quante stanze vuole? "))
    edificio=[]   
    nome_stanza=input("Inserire il nome della stanza: ")
    n_opere=int(input("opere volere lei: "))
    for a in range(n_opere):
        opere=input("Inserire il nome dell'opera che vuoi inserire: ")
        artista=input("Inserire l'artista dell'opera che vuoi inserire: ")
        anno=int(input("Inserire l'anno dell'opera che vuoi inserire: "))
        stanza={
            nome_stanza:{
                "opera":opere,
                "artista":artista,
                "anno":anno,
            }
        }
        edificio.append(stanza)

    print(edificio)
    with open("edificio.json", "w") as f:
        f.write(json.dumps(edificio))

    f.close()
def cancellazione_opere():
    with open("edificio.json", "r") as f:
        edificio=json.load(f)
    print(edificio)
    scelta=input("Scegliere l'opera nella stanza che si vuole cancellare: ")
    if scelta in edificio:
        print("a")
#menu
print("|-------------------------------------|")
print("|--------Menu dell'edificio-----------|")
print("|----1)Creazione di una stanza--------|")
print("|----2}Visualizzazione delle stanze---|")
print("|----3}Cancellare una opera-----------|")
print("|----4}Cancellare una stanza----------|")
print("|-------------------------------------|")
menu=input("cosa vuole fare? ")
if menu == "1":
    creazione_stanza()
if menu=="2":
    visualizza()
if menu=="3":
    cancellazione_opere()