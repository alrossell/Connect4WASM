// import React from "react";
import { Link, useNavigate } from "react-router-dom";

import React, { useState, useEffect } from "react";

import ConnectFourBinder from "./WASM/ConnectFourBinder.js";
import ConnectFourBinderWASM from "./WASM/ConnectFourBinder.wasm";

import "./Home.css";

export default function Home() {

    const [state, setState] = useState(
      {
        player1: true
      }
    );
    


    useEffect(() => {
      const instance = ConnectFourBinder({
        locateFile: () => {
          return ConnectFourBinderWASM;
        },
      });

      instance.then((module) => {
        let game = new module.ConnectFourGame();
      });
    }, []);

    return (
      <div className="Home">
        <h1>Connect Four</h1>
        <div className="Options">
          <Link
            to={{
              pathname: `/game?player1=true`
            }}
          >
            <h2 className="Player" id="Player1">
              Player 1
            </h2>
          </Link>
          <Link
            to={{pathname: `/game?player1=false`}}
          >
            <h2 className="Player" id="Player2">
              Player 2
            </h2>
          </Link>
        </div>
      </div>
    );
  }
  