<h1 align="center">🚀 C-Programming-Practice</h1>

<p align="center">
  <em>A collection of C projects exploring 3D math, matrix transformations, and SDL2 graphics.</em>
</p>

<hr>

<h2>🧊 Project: Rotating Cube (Euler Angles)</h2>

<p>This project renders a 3D wireframe cube using 1,200 points. It applies a complex rotation matrix (pitch, yaw, and roll) to every point in real-time.</p>

<details open>
  <summary><strong>🛠️ Installation & Setup</strong></summary>
  <br>
  <p>To fix <code>SDL2/SDL.h</code> missing errors, install the development headers:</p>
  
  <h4>🐧 Linux (Ubuntu/Debian/Mint)</h4>
  <pre><code>sudo apt update && sudo apt install libsdl2-dev</code></pre>

  <h4>🎩 Linux (Fedora/Arch)</h4>
  <ul>
    <li><strong>Fedora:</strong> <code>sudo dnf install SDL2-devel</code></li>
    <li><strong>Arch:</strong> <code>sudo pacman -S sdl2</code></li>
  </ul>
</details>

<hr>

<h2>🏗️ How to Compile</h2>

<p>Because this project uses both <strong>SDL2</strong> for graphics and <code>math.h</code> for rotation matrices, you must link both libraries:</p>

<pre><code>gcc rotating-cube/cube.c -o cube -lSDL2 -lm</code></pre>

<blockquote>
  <strong>⚠️ Linker Warning:</strong><br>
  If you see <code>undefined reference to cos</code> or <code>DSO missing</code>, ensure you have placed <strong>-lm</strong> at the end of your command. This tells the compiler to include the math library.
</blockquote>

<hr>

<h2>📐 The Math Behind the Rotation</h2>

<p>The cube rotates using a 3x3 rotation matrix for 3D space. It calculates the new position of each point using the <strong>Dot Product</strong> of the rotation matrix and the point's current vector:</p>



<ul>
  <li><strong>α (Alpha):</strong> Rotation around the Z-axis (Roll)</li>
  <li><strong>β (Beta):</strong> Rotation around the Y-axis (Yaw)</li>
  <li><strong>γ (Gamma):</strong> Rotation around the X-axis (Pitch)</li>
</ul>

<hr>

<h2>📅 Project Roadmap</h2>
<ul>
  <li>✅ Setup Basic Rendering & SDL Window</li>
  <li>✅ Implement 3D Point cloud</li>
  <li>✅ Matrix Rotation (Euler Angles)</li>
  <li>🚧 Perspective Projection (Coming Soon)</li>
  <li>📅 Line Drawing/Wireframe (Planned)</li>
</ul>

<div align="right">
  <em>Maintained by Luna</em>
</div>
