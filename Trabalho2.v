module TOP(input CLOCK_50, input reset, output LED);
   
   reg [25:0] cont;
   reg state;
   
   assign LED = state;
   
   always @(posedge CLOCK_50, reset) begin
   	if(reset == 1) begin
   	cont = 0;
   	state = 0;
   	end
      if(cont == 500) begin
	 state = ~state;
	 cont = 0;
      end
      else begin
	 cont <= cont+1;
      end
   end
   
endmodule
   
module test;
   
   reg reset, CLOCK_50;
   wire LED;
   
   TOP A(CLOCK_50, reset, LED);
   
   always #1 CLOCK_50 = ~CLOCK_50;
   
   initial begin
      $dumpvars(0, A);
      #0;
      reset <= 1;
      #1
      reset <= 0;
      CLOCK_50 <= 0;
      #5000;
      $finish;   
   end
endmodule
