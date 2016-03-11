module TOP(input CLOCK_50, output [1:0]LED);
   
   reg [32:0] cont;
   reg LedOn=0;
   
   assign LED[0] = LedOn;
   assign LED[1] = ~LedOn;
	
   always @(posedge CLOCK_50) begin		
      if(cont == 50000000) begin
	 LedOn = ~LedOn;
	 cont = 0;
      end
      else begin
	 cont <= cont+1;
      end
   end
   
endmodule
   
module test;
   
   reg clk;
   wire [1:0]Led;
   
   
   TOP A(clk, cont,
		Led);
   
   always #1 clk = ~clk;
   
   initial begin
      $dumpvars(0, A);
      #0;
      cont <= 0;
      clk <= 1;
      #400000000;
      $finish;   
   end
endmodule
