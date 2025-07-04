import itertools

def hamming_distance(a, b):
    return sum(x != y for x, y in zip(a, b))

def generate_codewords(n, k):
    # All possible codewords in k-ary base of length n
    all_words = list(itertools.product(range(k), repeat=n))
    codewords = []

    for word in all_words:
        if all(hamming_distance(word, cw) >= 3 for cw in codewords):
            codewords.append(word)

    return codewords

def format_codewords(codewords):
    return [''.join(map(str, word)) for word in codewords]

# Example usage
n = 10  # length of codewords
k = 3  # binary
codewords = generate_codewords(n, k)
formatted = format_codewords(codewords)
print(f"Generated {len(formatted)} codewords:")
print('\n'.join(formatted))

