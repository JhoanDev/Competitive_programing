saida = ""
atual = 'N'
linha = ""
while True:
    try:
        linha = input()
        x, y, z = [abs(int(v)) for v in linha.split()]
        if (x > y) and (x > z):
            if (atual == 'N'):
                saida += "A"
                atual = 'A'
            elif (atual == 'D'):
                saida += "U"
                atual = 'U'
            elif (atual == 'U'):
                saida += "D"
                atual = 'D'
            elif (atual == 'A'):
                saida += "N"
                atual = 'N'

        if (y > x) and (y > z):
            if (atual == 'N'):
                saida += "U"
                atual = 'U'
            elif (atual == 'D'):
                saida += "A"
                atual = 'A'
            elif (atual == 'U'):
                saida += "N"
                atual = 'N'
            elif (atual == 'A'):
                saida += "D"
                atual = 'D'

        if (z > x) and (z > y):
            if (atual == 'N'):
                saida += "D"
                atual = 'D'
            elif (atual == 'D'):
                saida += "N"
                atual = 'N'
            elif (atual == 'U'):
                saida += "A"
                atual = 'A'
            elif (atual == 'A'):
                saida += "U"
                atual = 'U'

    except EOFError:
        break

print(saida)
