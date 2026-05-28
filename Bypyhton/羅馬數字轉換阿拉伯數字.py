def romanToInt(s: str) -> int:
    num = 0
    i = 0
    while i < len(s):
        change = 0
        if s[i] == 'I': change = 1
        elif s[i] == 'V': change = 5
        elif s[i] == 'X': change = 10
        elif s[i] == 'L': change = 50
        elif s[i] == 'C': change = 100
        elif s[i] == 'D': change = 500
        elif s[i] == 'M': change = 1000

        if i != len(s) - 1:
            if s[i] == 'I' and s[i + 1] == 'V': change = 4; i += 1
            elif s[i] == 'I' and s[i + 1] == 'X': change = 9; i += 1
            elif s[i] == 'X' and s[i + 1] == 'L': change = 40; i += 1
            elif s[i] == 'X' and s[i + 1] == 'C': change = 90; i += 1
            elif s[i] == 'C' and s[i + 1] == 'D': change = 400; i += 1
            elif s[i] == 'C' and s[i + 1] == 'M': change = 900; i += 1

        num += change
        i += 1

    return num
