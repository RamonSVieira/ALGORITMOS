def calcular_media_provas(notas):
    soma = sum(notas)
    return soma / len(notas)

def obter_kesima_maior_nota(notas, k):
    notas.sort(reverse=True)
    return notas[k-1]

while True:
    try:
        n, k = map(int, input().split())
        notas = list(map(int, input().split()))

        media_provas = calcular_media_provas(notas)
        kesima_maior_nota = obter_kesima_maior_nota(notas, k)

        nota_final = (media_provas + kesima_maior_nota) / 2

        print(f"{nota_final:.1f}")
    except EOFError:
        break
