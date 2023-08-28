class Solution(object):

    def reverseWords(self, s):
      words = s.split()
      words.reverse()

      reversed_string = ' '.join(words)

      return reversed_string
        