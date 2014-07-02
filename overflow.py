def digit(t):
    num = t
    digits = 0

    while(num):
        num /= 10
        digits += 1
    return digits

def overflow(num):
    digits = digit(num)

    if (digits <= 4):
        return 0
    else:
        permitted = num % 10000
        overflow = num / 10000
        return overflow

ans = overflow(521456)

print(ans)
        
