import React, { useState, useEffect } from "react";
import { Link } from "react-router-dom";

import Row from "./Row"

import blueTile from "./assests/BlueTile.png";
import redTile from "./assests/RedTile.png";
import emptyTile from "./assests/EmptyTile.png";

import ConnectFourBinder from "./WASM/ConnectFourBinder.js";
import ConnectFourBinderWASM from "./WASM/ConnectFourBinder.wasm";

import "./Game.css"

const rowCount = 6
const colCount = 7

function Game(props) {
  console.log(props.location.state)
  const board = new Array(colCount)
    .fill(0)
    .map(() => new Array(rowCount).fill(emptyTile));
  const [gameState, changeGameState] = useState(board);
  const [cppGameState, changeCppGameState] = useState(null);
  const [turnCount, changeTurnCount] = useState(0);

  useEffect(() => {
    const instance = ConnectFourBinder({
      locateFile: () => {
        return ConnectFourBinderWASM;
      },
    });

    instance.then((module) => {
      let game = new module.ConnectFourGame();
      changeCppGameState(game);
    });
  }, []);

  const [player1, setPlayer] = useState(true);

  function placePiece(colIndex, player) {
    let newGameState = gameState;
    let newRow = cppGameState.placePiece(player, colIndex + 1);

    if (newRow !== -1) {
      newGameState[colIndex][rowCount - newRow] = player ? redTile : blueTile;
    } else {
      return false
    }

    if (cppGameState.checkFour()) {
      alert(`Player ${player ? "one" : "two"} Wins!`);
      newGameState = new Array(colCount)
        .fill(0)
        .map(() => new Array(rowCount).fill(emptyTile));
      cppGameState.newGame();
    }
    return true
  }

  const newGame = () => {
    let newBoard = new Array(colCount)
    .fill(0)
    .map(() => new Array(rowCount).fill(emptyTile));
    changeGameState(newBoard);
    cppGameState.newGame();
    changeTurnCount(0);
  }

  const playerTurn = (colIndex) => {
    if (placePiece(colIndex, player1)) {
      let cpuColIndex = cppGameState.nextMove(!player1, 15);
      placePiece(cpuColIndex-1, !player1);
      changeTurnCount(turnCount + 2);
    } else {
      alert("Column Full");
    }
  };

  return (
    <div className="Game">
      <div className="GameContainer">
        {gameState.map((col, index) => (
          <div key={index} className="col" onClick={() => playerTurn(index)}>
            <Row key={index} tiles={col} />
          </div>
        ))}
      </div>
      <div className="navBar">
        <Link className="gameLink" to="../">
          Home
        </Link>
        <Link className="gameLink" to="../game/" onClick={() => newGame()}>
          New game
        </Link>
      </div>
    </div>
    
  );
}

export default Game;
