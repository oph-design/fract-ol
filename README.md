
<a name="readme-top"></a>




<h1 align="center">Fractol</h1>
<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/oph-design/fract-ol?color=lightblue" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/oph-design/fract-ol?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/oph-design/fract-ol?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/created-at/oph-design/fract-ol?color=green" />
</p>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#examples">Usage</a></li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

<p align="center">
<img width="457" alt="Screen Shot 2024-03-20 at 4 02 03 PM" src="https://github.com/oph-design/fract-ol/assets/115570424/13a830be-51f3-417d-8267-4a2253777a98">
</p>


A fractal is a mathematical formular that is intended to be used recursively, meaning the last result in the input for the next iteartion. It is possible to create images with infinite depht from these formulars by applying them to every point in an imaginary plane. The point gets colored based on the formualrs results after a predetermined number of iterations. The colloring follows these criteria:</br>
The result is lower than 2 -> the point gets colored black </br>
The result is above 2 -> the point gets colored based on the number of iterations it took to get above 2



<!-- GETTING STARTED -->
## Getting Started

The following contains a description of how to use the program. It is recommend to run in an unix (linux or mac) environment.
As installing make and compilers in windows can be quite tedious. You can find a tutorial and setting up an ubuntu virtual machine <a href="https://www.linkedin.com/pulse/how-install-ubuntu-virtualbox-md-emamul-mursalin/">here</a>

### Prerequisites

You need to have make, gcc and the glfw library installed. For mac you need also brew and xcode to perform the installation.
* linux (Debian based)
  ```sh
  sudo apt install build-essential
  sudo apt-get install libglfw3
  ```
* MAC-OS
  ```sh
  brew install glfw
  xcode-select --install
  ```

### Installation

1. Clone the repo
   ```sh
   git clone https://github.com/oph-design/fract-ol.git
   ```
2. Build the executabel at the root of the repository
   ```sh
   make fract-ol
   ```
4. Create alias for your shell, for easier usage
   ```sh
   echo "alias fractol=\"path-to-executable\"" >> $HOME/.zshrc
   ```



<!-- USAGE EXAMPLES -->
## Usage

You can start the program by running the executable with the desired fractal as parameter
   ```sh
   ./fractol mandelbrot
   ```
You can use your alias instead of ./fractol to execute from any directory

After start the program generates the pictures, there you can navigate like this:
  * Use `W` `A` `S` `D` keys to navigate anywhere
  * Use the scrollwheel to zoom in and out at the mouse position
  * Use `UP` and `DOWN` arrows to increase and decrease the resolution
  * Use `LEFT` and `RIGHT` arrows to change the color sceme

Instead of `mandelbrot` you can also use `julia` or `burning_ship` as parameters. </br>
The `julia` paramater forces you to provide 2 additional number paramaters between 1 and 6 to render specific versions of that fractal.



<!-- EXMAPLES -->
## Examples

### Mandelbrot
   ```sh
   ./fractol mandelbrot
   ```
<img width="1457" alt="Screen Shot 2024-03-20 at 4 02 03 PM" src="https://github.com/oph-design/fract-ol/assets/115570424/bcada616-4425-4824-80a7-29f8fe215d45">

<p></p>

### Julia
   ```sh
   ./fractol julia 2 5
   ```
<img width="1477" alt="Screen Shot 2024-03-20 at 4 52 07 PM" src="https://github.com/oph-design/fract-ol/assets/115570424/af6db1cb-189c-4fa3-b045-4cd37ac3489f">

<p></p>

### Burning Ship
   ```sh
   ./fractol burning_ship
   ```

<img width="1477" alt="Screen Shot 2024-03-20 at 4 53 48 PM" src="https://github.com/oph-design/fract-ol/assets/115570424/9d1a70f4-f4ed-4b19-9994-bcce71a471a4">


<!-- CONTACT -->
## Contact

Ole-Paul Heinzelmann</br>
ole.paul.heinzelmann@protonmail.com </br>
<p></p>
<a href="https://www.linkedin.com/in/ole-paul-heinzelmann-a08304258/">
<img alt="linkedin shield" src="https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555" />
</a></br> 

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/oph-design/fract-ol.svg?style=for-the-badge
[contributors-url]: https://github.com/oph-design/fract-ol/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/oph-design/fract-ol.svg?style=for-the-badge
[forks-url]: https://github.com/oph-design/fract-ol/network/members
[stars-shield]: https://img.shields.io/github/stars/oph-design/fract-ol.svg?style=for-the-badge
[stars-url]: https://github.com/oph-design/fract-ol/stargazers
[issues-shield]: https://img.shields.io/github/issues/oph-design/fract-ol.svg?style=for-the-badge
[issues-url]: https://github.com/oph-design/fract-ol/issues
[license-shield]: https://img.shields.io/github/license/oph-design/fract-ol.svg?style=for-the-badge
[license-url]: https://github.com/oph-design/fract-ol/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/linkedin_username
[product-screenshot]: images/screenshot.png
[Next.js]: https://img.shields.io/badge/next.js-000000?style=for-the-badge&logo=nextdotjs&logoColor=white
[Next-url]: https://nextjs.org/
[React.js]: https://img.shields.io/badge/React-20232A?style=for-the-badge&logo=react&logoColor=61DAFB
[React-url]: https://reactjs.org/
[Vue.js]: https://img.shields.io/badge/Vue.js-35495E?style=for-the-badge&logo=vuedotjs&logoColor=4FC08D
[Vue-url]: https://vuejs.org/
[Angular.io]: https://img.shields.io/badge/Angular-DD0031?style=for-the-badge&logo=angular&logoColor=white
[Angular-url]: https://angular.io/
[Svelte.dev]: https://img.shields.io/badge/Svelte-4A4A55?style=for-the-badge&logo=svelte&logoColor=FF3E00
[Svelte-url]: https://svelte.dev/
[Laravel.com]: https://img.shields.io/badge/Laravel-FF2D20?style=for-the-badge&logo=laravel&logoColor=white
[Laravel-url]: https://laravel.com
[Bootstrap.com]: https://img.shields.io/badge/Bootstrap-563D7C?style=for-the-badge&logo=bootstrap&logoColor=white
[Bootstrap-url]: https://getbootstrap.com
[JQuery.com]: https://img.shields.io/badge/jQuery-0769AD?style=for-the-badge&logo=jquery&logoColor=white
[JQuery-url]: https://jquery.com
