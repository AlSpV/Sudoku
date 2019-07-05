


    let example = [1, 2, 3, 4, 5, 6, 7, 8, 9]
    let square = [
      ["1", "_", "5",],
      ["_", "9", "_",],
      ["2", "_", "_",],
    ]
    
    function searchSudoku(square){
      let buf = [];
      for (let i = 0; i < square.length; i++) {
        for (let j = 0; j < square[i].length; j++) {
          if (!isNaN(parseInt(square[i][j]))){        
            buf.push(square[i][j])
          }
        }
      }
      console.log(buf);
    }
    
    console.log(searchSudoku (square))

    Array.prototype.diff = function(a) {
        return this.filter(function(i) {return a.indexOf(i) < 0;});
    };
    
    console.log(example.diff(buf))






    