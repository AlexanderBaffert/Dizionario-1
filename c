#Baffert ALexander 4M
#Es5
import json

def visualizza():
    with open("edificio.json", "r") as f:
        edificio = json.load(f)
    print(edificio)
def creazione_stanza():
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
                opere:{
                    "artista":artista,
                    "anno":anno,
                }
            }
        }
        edificio.append(stanza)
    with open("edificio.json", "w") as f:
        f.write(json.dumps(edificio))
    f.close()

def cancellazione_opere():
    with open("edificio.json", "r") as f:
        edificio = json.load(f)

    print(edificio)

    scelta = input("Scegliere la stanza/opera da cancellare (utilizza il percorso completo, ad esempio 'stanza/opera'): ")

    # Dividi il percorso nelle chiavi nidificate
    chiavi = scelta.split("/")

    # Iniziamo con il dizionario principale
    dizionario_corrente = edificio

    # Scansiona le chiavi nidificate per trovare la stanza/opera specifica
    print(chiavi)
    for opera in dizionario_corrente:
        if chiavi[0] in opera.keys() and chiavi[1] in opera[chiavi[0]].keys():
            del opera[chiavi[0]][chiavi[1]]
            print("Stanza/opera cancellata con successo.")
            print(dizionario_corrente)
        else:
            print(f"La stanza/opera '{scelta}' non esiste nel dizionario.")

    # Sovrascrivi il file JSON con il dizionario modificato
    with open("edificio.json", "w") as f:
        json.dump(edificio, f, indent=4)
# Menu
print("|--------------------------------------|")
print("|--------Menu dell'edificio------------|")
print("|----1) Creazione di una stanza--------|")
print("|----2) Visualizzazione delle stanze---|")
print("|----3) Cancellare una opera-----------|")
print("|--------------------------------------|")

menu = input("Cosa vuole fare? ")

if menu == "1":
    creazione_stanza()
if menu == "2":
    visualizza()
if menu == "3":
    cancellazione_opere()
