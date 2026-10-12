class Solution:
    def findWords(self, words: list[str]) -> list[str]:
        r1="qwertyuiop"
        r2="asdfghjkl"
        r3="zxcvbnm"
        result=[]
        for word in words:
            w=word.lower()
            if all(c in r1 for c in w) or all(c in r2 for c in w) or all(c in r3 for c in w):
                result.append(word)
        return result