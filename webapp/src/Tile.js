import React from "react";
import "./Tile.css";

function Tile(props) {
  return (
    <div className="tile">
      <img className="image" src={props.tile} />
    </div>
  );
}

export default Tile;
