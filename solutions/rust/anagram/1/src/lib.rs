use std::collections::HashSet;

pub fn anagrams_for<'a>(word: &str, possible_anagrams: &[&'a str]) -> HashSet<&'a str> {
    let word = word.to_lowercase();
    let mut word_chars: Vec<char> = word.chars().collect();
    word_chars.sort();

    let mut anagrams = HashSet::new();
    for &possible_anagram in possible_anagrams {
        let possible_anagram_lower = possible_anagram.to_lowercase();
        if possible_anagram_lower.len() != word.len() || possible_anagram_lower == word {
            continue;
        }
        let mut possible_anagram_chars: Vec<char> = possible_anagram_lower.chars().collect();
        possible_anagram_chars.sort();
        if possible_anagram_chars == word_chars {
            anagrams.insert(possible_anagram);
        }
    }
    anagrams
}