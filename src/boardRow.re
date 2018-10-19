open SharedTypes;

let component = ReasonReact.statelessComponent("BoardRow");

let make = (~gameState: gameState, ~onMark, ~row: row, ~index: int, _children) => {
  ...component,
  render: _ =>
    <div className="board-row">
      (
        row
        |> List.mapi((ind: int, value: field) => {
            let id = string_of_int(index) ++ string_of_int(ind);
            <Square
              key=id
              value
              gameState
              onMark=(() => onMark(id))
            />;
           })
        |> Array.of_list
        |> ReasonReact.array
      )
    </div>,
};
