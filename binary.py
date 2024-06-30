def Binary(n):
    if n == 1:
        return "1"
    return Binary(n//2) + str(n%2)

n = int(input())
print(Binary(n))
