# Shared FIR Q15 vectors

Run `python tools/generate_fir_vectors.py --check` from the repository root.
Omit `--check` to regenerate the committed CSV files with the independent Python
integer/Fraction reference. CTest consumes these same files for C++ floating
convolution and `dsp_core::dsp::convolve_q15`.

Inputs and coefficients are signed Q1.15 integers. Output is full convolution
including the zero-padded tail; state starts at zero. The fixed path accumulates
in int64, rounds once to nearest with ties away from zero and saturates to
[-32768, 32767]. At most 65536 taps are accepted. The float column is the
unclipped convolution of the quantized operands, not a separately designed
floating filter. Unclipped fixed output must agree within half a Q15 LSB.

Cases exercise impulse response, signed samples/taps, positive and negative
rounding ties, both saturation rails and the -32768 endpoint. Plain CSV allows
MATLAB (`readtable`) and a future RTL testbench to consume the identical data.
This is Python/C++ simulation evidence; MATLAB, RTL and board agreement remain
unmeasured. It does not establish filter-design quantization error or RF accuracy.
