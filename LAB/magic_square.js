function generateMagicSquare(n) {
    if (n % 2 === 0) {
        console.log("Magic square is only possible for odd numbers.");
        return;
    }

    // Initialize n x n matrix filled with 0
    const square = Array.from({ length: n }, () => Array(n).fill(0));

    let i = 0;
    let j = Math.floor(n / 2);

    for (let k = 1; k <= n * n; k++) {
        square[i][j] = k;

        // Store old position before moving
        let newI = (i - 1 + n) % n;
        let newJ = (j + 1) % n;

        if (square[newI][newJ] !== 0) {
            i = (i + 1) % n; // Move down
        } else {
            i = newI;
            j = newJ;
        }
    }

    // Print the magic square
    console.log(`Magic Square of order ${n}:`);
    for (let row of square) {
        console.log(row.map(num => num.toString().padStart(4, ' ')).join(''));
    }
}

const n = 5; 
generateMagicSquare(n);

