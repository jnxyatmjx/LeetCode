> - Tensors(张量) are a specialized data structure that are very similar to arrays(向量) and matrices(矩阵).
>
> - `torch.autograd` is PyTorch’s automatic differentiation engine(自动微分引擎) that powers neural network training. Generally speaking, ``torch.autograd`` is an engine for computing **vector-Jacobian product**. That is, given any vector $\vec{v}$, compute the product $J^{T}\cdot \vec{v}$
>
>- In this **DAG**, leaves are the input tensors, roots are the output tensors. By tracing this graph from roots to leaves, you can automatically compute the gradients using the chain rule.
>
> - This `grad_fn` gives us a hint that when we execute the backpropagation(反向传播) step and compute gradients(梯度), we’ll need to compute the derivative(导数) of $Sin(x)$ for all this tensor’s inputs.
>
> - autograd class is just a Jacobian-vector product computing engine. A [Jacobian matrix](https://en.wikipedia.org/wiki/Jacobian_matrix_and_determinant)(雅各布矩阵) in very simple words is a matrix representing all the possible partial derivatives(偏导数) of two vectors. It’s the gradient of a vector with respect to another vector.