[%bs.raw {|require('./game.css')|}];

open SharedTypes;

type action =
  | ClickSquare(string)
  | Restart;

let initialState = {
  board: [
    [Empty, Empty, Empty],
    [Empty, Empty, Empty],
    [Empty, Empty, Empty],
  ],
  gameState: Playing(Cross),
};

let component = ReasonReact.reducerComponent("Game");

let make = _children => {
  ...component,
  initialState: () => initialState,
  reducer: (action: action, state: state) =>
    switch(action) {
      | Restart => ReasonReact.Update(initialState)
      | ClickSquare((id: string)) =>
        /* let updatedBoard = updateBoard(state.board, state.gameState, id);
        ReasonReact.Update({
          board: updatedBoard,
          gameState: checkGameState3x3(updatedBoard, state.board, state.gameState),
        }); */
        ReasonReact.Update(initialState)
    },
  render: (self) =>
    <div className="game">
      <Board
        state=self.state
      />
    </div>
}
