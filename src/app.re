let component = ReasonReact.statelessComponent("App");
let make = _children => {
  ...component,
  render: _self =>
    <>
       <div className="title">
         (ReasonReact.string("Tic Tac Toe Joe"))
       </div>
       <div className="not-title">
         (ReasonReact.string("Not the real title"))
       </div>
       /* <Game /> */
    </>,
};
