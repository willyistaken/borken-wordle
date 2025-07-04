#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>
#include<random>
#include <algorithm>

using namespace std;

using Codeword = vector<int>;
int hamming_distance(const Codeword& a, const Codeword& b) {
    int d = 0;
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) ++d;
    }
    return d;
}

void generate_codewords(int n, int k,int d, vector<Codeword>& codebook) {
    // Total number of codewords = k^n
    long long total = pow(k, n);
    vector<Codeword> all_words;

    // Generate all words
    for (long long i = 0; i < total; ++i) {
        Codeword word(n);
        long long x = i;
        for (int j = n - 1; j >= 0; --j) {
            word[j] = x % k;
            x /= k;
        }
        all_words.push_back(word);
    }

    // Greedy selection of codewords
    for (const auto& word : all_words) {
        bool ok = true;
        for (const auto& selected : codebook) {
            if (hamming_distance(word, selected) < d) {
                ok = false;
                break;
            }
        }
        if (ok) codebook.push_back(word);
    }
}

void print_codewords(const vector<Codeword>& codebook) {
    for (const auto& word : codebook) {
        for (int d : word) cout << d;
        cout << '\n';
    }
}

int main() {
    int n = 20; // codeword length
    int k = 2; // base
	int d = 6;
	for(int i=1;i<=n;i++){
    	vector<Codeword> codebook;
    	generate_codewords(i, k, d, codebook);
    	cout << "Generated " << codebook.size() << " codewords:\n";
	}

//	print_codewords( codebook);

    return 0;
}

