import React from "react";
import Tile from "./Tile"

function Row(props) {
  return (
    <>
      {props.tiles.map((tile, index) => {
        return <Tile key={index} tile={tile} />;
      })}
    </>
  );
}

export default Row;
  