import React, { useState, useEffect } from "react";
import Row from "./Row"

import findFour from "./findFour.js"

import blueTile from "./assests/BlueTile.png";
import redTile from "./assests/RedTile.png";
import emptyTile from "./assests/EmptyTile.png";

import ConnectFourBinder from "./WASM/ConnectFourBinder.js";
import ConnectFourBinderWASM from "./WASM/ConnectFourBinder.wasm";

import "./Game.css"

const rowCount = 6
const colCount = 7

function findEmptyTile(col) {
  for (let index = rowCount - 1; index >= 0; index--) {
    if (col[index] === emptyTile) {
      return index;
    }
  }
  return -1;
}

function Game() {
  const board = new Array(colCount)
    .fill(0)
    .map(() => new Array(rowCount).fill(emptyTile));
  const [gameState, changeGameState] = useState(board);

  const [player, setPlayer] = useState(true);

  const placeTile = (colIndex) => {
    let newGameState = gameState;
    let rowIndex = findEmptyTile(newGameState[colIndex]);
    if (rowIndex !== -1) {
      newGameState[colIndex][rowIndex] = player ? redTile : blueTile;
      setPlayer(!player);
    }
    changeGameState([...newGameState]);

    if (findFour(gameState, colIndex, rowIndex)) {
      alert(`Player ${player ? "one" : "two"} Wins!`);
      let newBoard = new Array(colCount)
        .fill(0)
        .map(() => new Array(rowCount).fill(emptyTile));
      changeGameState(newBoard);
    }
  };

  const sample = ConnectFourBinder({
    locateFile: () => {
      return ConnectFourBinderWASM;
    },
  });

  sample.then((module) => {
    var instance = new module.ConnectFourGame();
    console.log(instance.getMove());
    console.log(instance.placePiece(true, 1));
    console.log(instance.placePiece(true, 1));
    console.log(instance.placePiece(true, 1));
    console.log(instance.placePiece(true, 1));
  })

  return (
    <div className="Game">
      {gameState.map((col, index) => (
        <div key={index} className="col" onClick={() => placeTile(index)}>
          <Row key={index} tiles={col} />
        </div>
      ))}
    </div>
  );
}

export default Game;
