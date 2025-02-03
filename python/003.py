largest_pal = 0

# Main loop to check every number
for i in range(999, 0, -1):
    for j in range(999, i, -1):
        res = i * j
        res_str = str(res)
        res_reversed = res_str[::-1]
        if res_str != res_reversed:
            continue

        if res > largest_pal:
            print(i, j)
            print(res)
            largest_pal = res
