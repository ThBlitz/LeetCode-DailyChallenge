from collections import defaultdict

def findSubstring(s, words):
        
        window = defaultdict(int)
        check_set = defaultdict(int)
            
        window_len = len(words)
        pointer_len = len(words[0])
        
        result = []
        
        for k in range(pointer_len):
            
            for word in words:
                check_set[word] += 1
        
            
            for i in range(k , k + window_len * pointer_len, pointer_len):
                j = i + pointer_len
                window[s[i: j]] += 1
                if s[i: j] not in check_set:
                    check_set[s[i: j]] = 0

            for i in range(k + window_len * pointer_len, len(s) + 1, pointer_len):
                x = i - window_len * pointer_len
                if window == check_set:
                    result.append(x)
                window[s[x: x + pointer_len]] -= 1
                window[s[i: i + pointer_len]] += 1
                if s[i: i + pointer_len] not in check_set:
                    check_set[s[i: i + pointer_len]] = 0
            
            window.clear()
            check_set.clear()
            
        return result


s = "lingmindraboooooooofooowingdingbarrwingmonkeypoundcake"
words = ["fooo","barr","wing","ding","wing"]

print(f" s : {s} \n words : {words} \n result : {findSubstring(s, words)}")
