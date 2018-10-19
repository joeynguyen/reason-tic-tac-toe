open SharedTypes;

let setStatus = (gameState: gameState) =>
  switch (gameState) {
  | Playing(Cross) => "Cross is playing"
  | Playing(Circle) => "Circle is playing"
  | Winner(Cross) => "The winner is Cross"
  | Winner(Circle) => "The winner is Circle"
  | Draw => "Draw"
  };

let component = ReasonReact.statelessComponent("Board");

let make = (~state: state, ~onMark, ~onRestart, _children) => {
  ...component,
  render: _ =>
    <div className="game-board">
      (
        state.board
        |> List.mapi(
            (index: int, row: row) =>
            <BoardRow
              key=(string_of_int(index))
              gameState=state.gameState
              onMark
              row
              index
            />
          )
        |> Array.of_list
        |> ReasonReact.array
      )
      <div className="status">
        (state.gameState |> setStatus |> ReasonReact.string)
      </div>
      (
        /* if game is game complete, show "Restart" button */
        switch(state.gameState) {
          | Playing(_) => ReasonReact.null
          | _ =>
              <button className="restart" onClick=onRestart >
                (ReasonReact.string("Restart"))
              </button>
        }
      )
    </div>
}
