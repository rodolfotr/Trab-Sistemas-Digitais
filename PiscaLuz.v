module Pisca(
    input clk,
    output fio
  );
  
    assign fio = clk;

endmodule

module Test(output luz);

  reg clk;
  wire fio;
  
    always #3 clk <= ~clk;
    
    Pisca luz(clk, fio);

  initial begin
    $dumpvars(0, luz);
    clk <= 0;
    #300;
    $finish;
  end
endmodule
