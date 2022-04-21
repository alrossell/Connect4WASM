import React from "react";
import Home from "./Home"
import Game from "./Game"
import {
    BrowserRouter as Router,
    Routes,
    Route
  } from "react-router-dom";

export default function App() {
    return (
        <div className="App">
            <Router>
                <Routes>
                    <Route path="/" element={<Home />} />
                    <Route path="game/" element={<Game />} />
                </Routes>
            </Router>
        </div>
    );
  }