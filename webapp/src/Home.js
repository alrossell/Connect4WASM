import React from "react";
import { Link } from "react-router-dom";

import "./Home.css";

export default function Home() {
    return (
      <div className="Home">
        <h1>Connect Four</h1>
        <div className="Options">
          <Link to={{
                  pathname: "game",
                  state: {
                    player1: true,
                  },
                }}>
            <h2 className="Player" id="Player1">Player 1</h2>
          </Link>
          <Link to="game/">
            <h2 className="Player" id="Player2">Player 2</h2>
          </Link>
        </div>
      </div>
    );
  }
  