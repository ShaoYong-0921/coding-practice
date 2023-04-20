from collections import Counter as cnt

def is_palindrome():
    list_letter = []
    list_ans = []

    for i in range(65, 91):
        list_letter.append(chr(i))

    n = input()
    n = n.upper()

    for word in n:
        if word in list_letter:
            list_ans.append(word)
    #print(list_ans)
    
    ans_cnt = cnt(list_ans)
    # print(ans_cnt)
    count = 0

    for i in ans_cnt:
        if ans_cnt[i] % 2 == 1:
            count += 1
            # print(f'{count=}, {ans_cnt[i]=}')       
            if count == 2:
                return 'no...'
            continue
    return 'yes !'

while True:
    try:
        print(is_palindrome())
    except:
        break