import React from "react";
import { createRoot } from "react-dom/client";

import Game from "./src/Game";

const container = document.getElementById("root");
const root = createRoot(container); 
root.render(
  <div>
    <Game />
  </div>
);
