//8) GCD
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
// GCD(LCM) = A(B). We can find Lcm directly from this formula. Remember this please