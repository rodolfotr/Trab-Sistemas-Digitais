module Pisca(
    input luz,
    output fio
  );
assign fio = luz;

endmodule

module Test;

  reg luz;
    always #3 luz <= ~luz;

  initial begin
    $dumpvars(0, luz);
    luz <= 0;
    #500;
    $finish;
  end
endmodule
