// 연결할 컴포넌트 import
import { createWebHistory, createRouter } from 'vue-router';
import MainView from "../views/MainView.vue";
import AdminView from "../views/AdminView.vue";
import AdminMainView from "../components/Admin/AdminMainView.vue";
// import MainBluePrint from "../components/BluePrint/MainBluePrint.vue";
// import MainGraph from "../components/graph/MainGraph.vue";
// import LoginView from "../views/LoginView.vue";
// import AdminLogin from "../components/Login/AdminLogin.vue";
// import CustomerLogin from "../components/Login/CustomerLogin.vue";
// import MainLogistics from "../components/Logistics/MainLogistics.vue";
// import MainMachine from "../components/Machine/MainMachine.vue";
// import OrderByDate from "../components/Order/OrderByDate.vue";
// import OrderByRegion from "../components/Order/OrderByRegion.vue";
// import AdminRegist from "../components/Regist/AdminRegist.vue";
// import CustomerRegist from "../components/Regist/CustomerRegist.vue";

// 라우터 설계
const routes = [
    {
        path: '/',
        name: 'MainView',
        component: MainView,
    },
    {
        path: '/admin',
        name: 'AdminView',
        component: AdminView,
        children: {
            path: '/',
            name: 'AdminMainView',
            component: AdminMainView,
        }
    }
]

// 라우터 생성
// 루트를 내부에 생성해도 되지만 코드가 복잡해지기 때문에 외부에 배열 형태로 생성한다
const router = createRouter({
    history: createWebHistory(),
    routes,
})

// 라우터 추출
// 추출한 라우터는 main.js에서 import하여 사용
export default router