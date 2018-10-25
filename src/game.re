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

let updateBoard = (board: board, gameState: gameState, id) =>
  board
  |>  List.mapi((ind: int, row: row) =>
    row
    |> List.mapi((index: int, value: field) =>
      string_of_int(ind) ++ string_of_int(index) == id ?
        switch (gameState: gameState, value: field) {
          | (Playing(_), Marked(_)) => value /* don't change if square is taken */
          | (Playing(player), Empty) => Marked(player) /* mark square */
          | (_, _) => Empty /* game is over, don't mark */
        } : value
    )
  );

let component = ReasonReact.reducerComponent("Game");

let make = _children => {
  ...component,
  initialState: () => initialState,
  reducer: (action: action, state: state) =>
    switch(action) {
      | Restart => ReasonReact.Update(initialState)
      | ClickSquare((id: string)) =>
        let updatedBoard = updateBoard(state.board, state.gameState, id);
        ReasonReact.Update({
          board: updatedBoard,
          /* gameState: checkGameState3x3(updatedBoard, state.board, state.gameState), */
          gameState: state.gameState
        });
    },
  render: (self) =>
    <div className="game">
      <Board
        state=self.state
        onMark=(id => self.send(ClickSquare(id)))
        onRestart=(_evt => self.send(Restart))
      />
    </div>
}
