.. role:: hidden
    :class: hidden-section

torch.special
=============

A special function is a mathematical function that frequently arises in the
solutions of classical problems in fields like geometry, mathematical analysis,
or probability theory. PyTorch provides practical closed-form solutions for a
broad and deep set of special functions.

.. automodule:: torch.special
.. currentmodule:: torch.special

Elementary Functions
--------------------

Piecewise Functions
^^^^^^^^^^^^^^^^^^^

.. note::
    Many piecewise functions can be found in the ``torch`` module:

    * ``torch.abs``
    * ``torch.ceil``
    * ``torch.floor``
    * ``torch.heaviside``
    * ``torch.max``
    * ``torch.min``

Exponential Functions
^^^^^^^^^^^^^^^^^^^^^

.. note::
    The exponential function is found in the ``torch`` module:

    * ``torch.exp``

.. autofunction:: exp2
.. autofunction:: expit
.. autofunction:: expm1

Logarithmic Functions
^^^^^^^^^^^^^^^^^^^^^

.. note::
    Many logarithmic functions can be found in the ``torch`` module:

    * ``torch.log``
    * ``torch.log2``
    * ``torch.log10``

.. autofunction:: log1p
.. autofunction:: logit
.. autofunction:: logsumexp
.. autofunction:: xlog1py
.. autofunction:: xlogy

Trigonometric Functions
^^^^^^^^^^^^^^^^^^^^^^^

.. note::
    The **majority** of trigonometric, inverse trigonmetric, hyperbolic, and
    inverse hyperbolic functions are found in the ``torch`` module.

.. autofunction:: sinc

Logistic Functions
^^^^^^^^^^^^^^^^^^

.. autofunction:: softmax
.. autofunction:: log_softmax

Number Theoretic Functions
^^^^^^^^^^^^^^^^^^^^^^^^^^

.. autofunction:: round

Information Theoretic Functions
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. note::
    Loss functions (e.g., Huber and Kullback-Leibler divergence functions) are
    found in the ``torch.nn.functional`` module.

.. autofunction:: entr

Distance Functions
^^^^^^^^^^^^^^^^^^

.. note::
    Distance functions (e.g., cowise similarity and pairwise functions) are
    presently found in the ``torch.nn.functional`` module.

Error Functions and Exponential Integrals
-----------------------------------------

Error Functions
^^^^^^^^^^^^^^^

.. autofunction:: erf
.. autofunction:: erfc
.. autofunction:: erfcx
.. autofunction:: erfinv

Gamma and Related Functions
---------------------------

Gamma Functions
^^^^^^^^^^^^^^^

.. autofunction:: gammaln
.. autofunction:: multigammaln

Polygamma Functions
^^^^^^^^^^^^^^^^^^^

.. autofunction:: digamma
.. autofunction:: polygamma
.. autofunction:: psi

Orthogonal Polynomials
----------------------

Chebyshev Polynomials
^^^^^^^^^^^^^^^^^^^^^

.. autofunction:: chebyshev_polynomial_t
.. autofunction:: chebyshev_polynomial_u
.. autofunction:: chebyshev_polynomial_v
.. autofunction:: chebyshev_polynomial_w

Hermite Polynomials
^^^^^^^^^^^^^^^^^^^

.. autofunction:: hermite_polynomial_h
.. autofunction:: hermite_polynomial_he

Laguerre Polynomials
^^^^^^^^^^^^^^^^^^^^

.. autofunction:: laguerre_polynomial_l

Legendre Polynomials
^^^^^^^^^^^^^^^^^^^^

.. autofunction:: legendre_polynomial_p

Shifted Chebyshev Polynomials
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. autofunction:: shifted_chebyshev_polynomial_t
.. autofunction:: shifted_chebyshev_polynomial_u
.. autofunction:: shifted_chebyshev_polynomial_v
.. autofunction:: shifted_chebyshev_polynomial_w

Bessel and Related Functions
----------------------------

Bessel Functions
^^^^^^^^^^^^^^^^

Bessel functions are the canonical solutions to Bessel’s differential equation:

.. math::
    x^{2}{\frac{d^{2}y}{dx^{2}}}+x{\frac{dy}{dx}}+\left(x^{2}-\alpha^{2}\right)y=0

Bessel equations arise everywhere. But, perhaps most relevantly to PyTorch
users, they occur in probability theory (e.g., the probability density function
of the product of two normally distributed random variables), signal processing
(e.g., analog filter design and FM synthesis), and physics (e.g.,
electromagnetic waves in a cylindrical waveguide, diffusion problems on
lattices, and the dynamics of floating bodies).

Bessel functions of the first kind, denoted :math:`J_{\alpha}(x)`, are solutions
to Bessel’s equation. For integer or positive :math:`\alpha`, Bessel functions
of the first kind are finite at the origin, :math:`x = 0`; while for negative
non-integer :math:`\alpha`, Bessel functions of the first kind diverge as
:math:`x` approaches zero. It is possible to define the function by its series
expansion around :math:`x = 0`, which can be found by applying the Frobenius
method to Bessel’s equation:

.. math::
    J_{\alpha}(x)=\sum_{m=0}^{\infty}{\frac{(-1)^{m}}{m!\Gamma(m+\alpha+1)}}{\left({\frac{x}{2}}\right)}^{2m+\alpha}

where :math:`\Gamma(x)` is the Euler gamma function (``torch.special.gamma``).

.. autofunction:: bessel_j0
.. autofunction:: bessel_j1

The Bessel functions of the second kind, denoted :math:`Y_{\alpha}(x)`, are
solutions to Bessel differential equation that have a singularity at the origin
and are multivalued. For non-integer :math:`\alpha`, :math:`Y_{\alpha}(x)` is
related to :math:`J_{\alpha}(x)` by:

.. math::
    Y_{\alpha}(x)={\frac{J_{\alpha }(x)\cos(\alpha\pi)-J_{-\alpha}(x)}{\sin(\alpha\pi)}}

In the case of integer order :math:`n`, the function is defined by taking the
limit as a non-integer :math:`\alpha` tends to :math:`n`:

.. math::
    Y_{n}(x)=\lim_{\alpha\to n}Y_{\alpha }(x)

In the case of non-negative integer order :math:`n`, the function is defined by
the series:

.. math::
    Y_{n}(x)=-{\frac{\left({\frac{x}{2}}\right)^{-n}}{\pi}}\sum_{k=0}^{n-1}{\frac{(n-k-1)!}{k!}}\left({\frac{x^{2}}{4}}\right)^{k}+{\frac{2}{\pi}}J_{n}(x)\ln{\frac{x}{2}}-{\frac{\left({\frac{x}{2}}\right)^{n}}{\pi}}\sum_{k=0}^{\infty}(\psi(k+1)+\psi(n+k+1)){\frac{\left(-{\frac{x^{2}}{4}}\right)^{k}}{k!(n+k)!}}

where :math:`\psi(x)` is the digamma function, the logarithmic derivative of the
gamma function (``torch.special.digamma``).

.. autofunction:: bessel_y0
.. autofunction:: bessel_y1

Modified Bessel Functions
^^^^^^^^^^^^^^^^^^^^^^^^^

Bessel functions are valid even for complex arguments :math:`x`, and an
important special case is that of an imaginary argument. In this case, the
solutions to the Bessel equation are denoted as the modified Bessel functions.

The modfified Bessel functions of the first kind, denoted :math:`I_{\alpha}(x)`,
are defined as:

.. math::
    I_{\alpha}(x)=i^{-\alpha}J_{\alpha}(ix)=\sum _{m=0}^{\infty }{\frac {1}{m!\,\Gamma (m+\alpha +1)}}\left({\frac {x}{2}}\right)^{2m+\alpha}

.. autofunction:: modified_bessel_i0
.. autofunction:: modified_bessel_i1

The modified Bessel functions of the second kind, denoted :math:`K_{\alpha}(x)`,
are defined as:

.. math::
    K_{\alpha}(x)={\frac{\pi}{2}}{\frac{I_{-\alpha}(x)-I_{\alpha}(x)}{\sin\alpha\pi}}

.. autofunction:: modified_bessel_k0
.. autofunction:: modified_bessel_k1

Scaled Modified Bessel Functions
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. autofunction:: i0e
.. autofunction:: i1e

Airy Functions
^^^^^^^^^^^^^^

The Airy functions, :math:`\operatorname{Ai}(x)` and
:math:`\operatorname{Ai}(x)`, are linearly independent solutions to the Stokes
differential equation:

.. math::
    {\frac{d^{2}y}{dx^{2}}}-xy=0

The Stokes equation is noteworthy, from an analytic perspective, because it is
the simplest second-order linear differential equation with a turning point (a
point where the character of the solutions changes from oscillatory to
exponential).

Airy functions are especially useful in computing other special functions.
Still, they arise elsewhere, most notably in fluid dynamics, optics, and wave
propagation.

For real values of :math:`x`, the Airy function of the first kind, denoted
:math:`\operatorname{Ai}(x)`, is typically defined by the improper Riemann
integral:

.. math::
    \operatorname{Ai}(x)={\dfrac{1}{\pi}}\int_{0}^{\infty}\cos\left({\dfrac{t^{3}}{3}}+xt\right)\,dt\equiv{\dfrac{1}{\pi}}\lim_{b\to\infty}\int_{0}^{b}\cos\left({\dfrac{t^{3}}{3}}+xt\right)\,dt

.. autofunction:: airy_ai

:math:`y = \operatorname{Ai}(x)` satisfies the Airy equation:

.. math::
    y''-xy=0.

This equation has two linearly independent solutions. Up to scalar
multiplication, :math:`\operatorname{Ai}(x)` is the solution subject to the
condition :math:`y \rightarrow 0` as :math:`x \rightarrow \infty`. The standard
choice for the other solution is the Airy function of the second kind,
denoted :math:`\operatorname{Bi}(x)`. It is defined as the solution with the
same amplitude of oscillation as :math:`\operatorname{Ai}(x)` as
:math:`x \rightarrow \infty` which differs in phase by :math:`\frac{\pi}{2}`:

.. math::
    \operatorname{Bi}(x)={\frac{1}{\pi}}\int_{0}^{\infty}\left[\exp \left(-{\tfrac{t^{3}}{3}}+xt\right)+\sin\left({\tfrac{t^{3}}{3}}+xt\right)\,\right]dt.

.. autofunction:: airy_bi

Zeta and Related Functions
--------------------------

Zeta Functions
^^^^^^^^^^^^^^

.. autofunction:: zeta

Probability Theoretic Functions
-------------------------------

Cumulative Distribution Functions
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. autofunction:: ndtr
.. autofunction:: ndtri
.. autofunction:: log_ndtr
