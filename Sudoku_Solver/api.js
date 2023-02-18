// Create an empty 9x9 grid
const grid = [];
for (let i = 0; i < 9; i++) {
  grid[i] = [];
  for (let j = 0; j < 9; j++) {
    grid[i][j] = 0;
  }
}

// Fill in the grid with random numbers
for (let i = 0; i < 9; i++) {
  for (let j = 0; j < 9; j++) {
    let num = Math.floor(Math.random() * 9) + 1;
    while (!isValid(grid, i, j, num)) {
      num = Math.floor(Math.random() * 9) + 1;
    }
    grid[i][j] = num;
  }
}

// Check if a number is valid at a given position
function isValid(grid, row, col, num) {
  // Check row
  for (let i = 0; i < 9; i++) {
    if (grid[row][i] === num) {
      return false;
    }
  }
  
  // Check column
  for (let i = 0; i < 9; i++) {
    if (grid[i][col] === num) {
      return false;
    }
  }
  
  // Check subgrid
  const subgridRow = Math.floor(row / 3) * 3;
  const subgridCol = Math.floor(col / 3) * 3;
  for (let i = subgridRow; i < subgridRow + 3; i++) {
    for (let j = subgridCol; j < subgridCol + 3; j++) {
      if (grid[i][j] === num) {
        return false;
      }
    }
  }
  
  return true;
}

// Print the grid
console.log(grid);
