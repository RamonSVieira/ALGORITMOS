def menor_quantidade_fatoriais(n):
    fatoriais = [1]  # Lista para armazenar os fatoriais
    i = 1
    while fatoriais[-1] <= n:
        i += 1
        fatorial = 1
        for j in range(1, i+1):
            fatorial *= j
        fatoriais.append(fatorial)

    dp = [float('inf')] * (n+1)  # Lista para armazenar os resultados intermediários
    dp[0] = 0

    for i in range(1, n+1):
        for fatorial in fatoriais:
            if fatorial > i:
                break
            dp[i] = min(dp[i], dp[i - fatorial] + 1)

    return dp[n]

# Leitura do valor de N
n = int(input())

# Chamada da função e exibição do resultado
print(menor_quantidade_fatoriais(n))
