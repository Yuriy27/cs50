import nltk

class Analyzer():
    """Implements sentiment analysis."""

    def __init__(self, positives, negatives):
        self.tokenizer = nltk.tokenize.TweetTokenizer()
        self.positive_words = self.load_words(positives)
        self.negative_words = self.load_words(negatives)

    def load_words(self, path):
        words = []
        with open(path) as fp:
            for line in fp:
                if line[0] != ';':
                    words.append(line.strip());
        return words

    def analyze(self, text):
        res = 0
        for word in self.tokenizer.tokenize(text):
            if word in self.positive_words:
                res += 1;
            if word in self.negative_words:
                res -= 1;
        return res
