const fs = require('fs');
const path = require('path');

// Read words from a file
function readWordsFromFile(filename) {
        const content = fs.readFileSync(filename, 'utf8');
        return content.split(/\s+/).filter(Boolean);
}

// Write merged words to output file
function writeMergedWords(file1Words, file2Words, outputFile) {
    const mergedWords = [...file1Words, ...file2Words];
    fs.writeFileSync(outputFile, mergedWords.join(' ') + '\n');
    return mergedWords;
}

// Get unique words and write to file
function getUniqueWords(words, uniqueFile) {
    const uniqueSet = new Set(words);
    const uniqueList = Array.from(uniqueSet);
    fs.writeFileSync(uniqueFile, uniqueList.join('\n'));
    return uniqueList;
}

// Count occurrences of unique words in a word list
function countOccurrences(words, uniqueWords) {
    return uniqueWords.map((unique) => words.filter((word) => word === unique).length);
}

// Print array nicely
function printArray(label, arr) {
    console.log(`${label}: [${arr.join(', ')}]`);
}

// Calculate cosine similarity
function cosineSimilarity(arrA, arrB) {
    let dotProduct = 0, magA = 0, magB = 0;

    for (let i = 0; i < arrA.length; i++) {
        dotProduct = dotProduct + arrA[i] * arrB[i];
        magA = magA + arrA[i]**2;
        magB = magB + arrB[i]**2;
    }

    const magnitude = Math.sqrt(magA) * Math.sqrt(magB);
    const similarity = dotProduct / magnitude;

    console.log(`Cosine similarity: ${similarity}`);
    console.log(`${(similarity * 100).toFixed(2)}% Similarity`);
}

function main() {
    const file1 = path.join(__dirname, 'file1.txt');
    const file2 = path.join(__dirname, 'file2.txt');
    const outputFile = path.join(__dirname, 'merged.txt');
    const uniqueFile = path.join(__dirname, 'unique.txt');

    const words1 = readWordsFromFile(file1);
    const words2 = readWordsFromFile(file2);
    
    console.log(`Total words in file1: ${words1.length}`);
    console.log(`Total words in file2: ${words2.length}`);

    const mergedWords = writeMergedWords(words1, words2, outputFile);
    const uniqueWords = getUniqueWords(mergedWords, uniqueFile);

    console.log(`Total unique words: ${uniqueWords.length}`);
    
    printArray('Words in file1', words1);
    printArray('Words in file2', words2);
    printArray('Unique words', uniqueWords);

    const occArrayA = countOccurrences(words1, uniqueWords);
    const occArrayB = countOccurrences(words2, uniqueWords);

    printArray('Array A', occArrayA);
    printArray('Array B', occArrayB);

    cosineSimilarity(occArrayA, occArrayB);
}

main();
