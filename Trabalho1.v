module Pisca(
    input clk,
    output fio
  );
  
    assign fio = clk;

endmodule

module Test(output V);

  reg clk;
  wire fio;
  
    always #3 clk <= ~clk;
    
    Pisca A(clk, fio);

  initial begin
    $dumpvars(0, A);
    clk <= 0;
    #300;
    $finish;
  end
endmodule
