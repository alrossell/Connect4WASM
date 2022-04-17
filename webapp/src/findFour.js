
export default function findFour(gameState, placedColIndex, placedRowIndex) {
    const colCount = gameState.length;
    const rowCount = gameState[0].length;
  let currentTile = gameState[placedColIndex][placedRowIndex];
  let currentTileCount = 0;

  let rowIndex;
  let colIndex;

  //Horizantial down
  for (rowIndex = placedRowIndex; rowIndex < rowCount; rowIndex++) {
    if (currentTile === gameState[placedColIndex][rowIndex]) {
      currentTileCount += 1;
    } else {
      break;
    }
  }

  if (currentTileCount === 4) {
    return true;
  }

  currentTileCount = 0;

  //Vertical to the right
  for (colIndex = placedColIndex; colIndex < colCount; colIndex++) {
    if (currentTile === gameState[colIndex][placedRowIndex]) {
      currentTileCount += 1;
    } else {
      break;
    }
  }

  if (currentTileCount === 4) {
    return true;
  }
  currentTileCount -= 1;

  //Vertical to the left
  for (colIndex = placedColIndex; colIndex >= 0; colIndex--) {
    if (currentTile === gameState[colIndex][placedRowIndex]) {
      currentTileCount += 1;
    } else {
      break;
    }
  }

  if (currentTileCount === 4) {
    return true;
  }

  currentTileCount = 0;

  //Diagonal from bottom left to up right

  //Diagonal up right
  for (
    colIndex = placedColIndex, rowIndex = placedRowIndex;
    colIndex < colCount && rowIndex >= 0;
    colIndex++, rowIndex--
  ) {
    if (currentTile === gameState[colIndex][rowIndex]) {
      currentTileCount += 1;
    } else {
      break;
    }
  }

  currentTileCount -= 1;
  //Diagonal bottom left
  for (
    colIndex = placedColIndex, rowIndex = placedRowIndex;
    colIndex >= 0 && rowIndex < rowCount;
    colIndex--, rowIndex++
  ) {
    if (currentTile === gameState[colIndex][rowIndex]) {
      currentTileCount += 1;
    } else {
      break;
    }
  }

  if (currentTileCount === 4) {
    return true;
  }

  currentTileCount = 0;

  //Diagonal from bottom right to up left

  //Diagonal up left
  for (
    colIndex = placedColIndex, rowIndex = placedRowIndex;
    colIndex >= 0 && rowIndex >= 0;
    colIndex--, rowIndex--
  ) {
    if (currentTile === gameState[colIndex][rowIndex]) {
      currentTileCount += 1;
    } else {
      break;
    }
  }

  currentTileCount -= 1;
  //Diagonal bottom right
  for (
    colIndex = placedColIndex, rowIndex = placedRowIndex;
    colIndex < colCount && rowIndex < rowCount;
    colIndex++, rowIndex++
  ) {
    if (currentTile === gameState[colIndex][rowIndex]) {
      currentTileCount += 1;
    } else {
      break;
    }
  }

  if (currentTileCount === 4) {
    return true;
  }

  return false;
}
