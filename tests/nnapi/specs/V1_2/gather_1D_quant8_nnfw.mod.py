# model
model = Model()
i1 = Input("op1", "TENSOR_QUANT8_ASYMM", "{4}, 0.5f, 1") # a vector of 4 qasymm8s
i2 = Input("op2", "TENSOR_INT32", "{2}") # another vector of 2 int32s
axis = Int32Scalar("axis", 0)
i3 = Output("op3", "TENSOR_QUANT8_ASYMM", "{2}, 0.5f, 1") # another vector of 2 qasymm8s
model = model.Operation("GATHER", i1, axis, i2).To(i3)

# Example 1. Input in operand 0,
input0 = {i1: # input 0
          [7, 9, 11, 13],
          i2: # input 1
          [2, 0]}

output0 = {i3: # output 0
           [11, 7]}

# Instantiate an example
Example((input0, output0))
